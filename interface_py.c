#include "interface_py.h"
#include <Python.h>
#include <stdio.h>
#include <ctype.h>
/* 
    - Sample implementation of interface_py.h
    - Caller must Initialize and Finalize python interpreter.
        (Py_Initialize() and Py_Finalize()).
*/

#define PY_FILE_NAME "manager" /* Name of the python file */

/* This function will be only used in this file.
   Calls a python functions, takes file name as parameter "fun_name".
   Returns an error_code.
*/
static error_code call_python_function(char *fun_name) {
    /* Add current directoy to system path, 
       so interpreter can find the manager.py file.
    */
    PyRun_SimpleString("import sys; sys.path.append(\".\")");
    PyObject *p_name = PyUnicode_FromString(PY_FILE_NAME);
    PyObject *p_module = PyImport_Import(p_name);
    Py_DECREF(p_name);

    error_code error = err_success; /* Assume err_success initially */
    if(p_module != NULL) {
        PyObject *p_fun = PyObject_GetAttrString(p_module, fun_name);
        if(PyCallable_Check(p_fun)) {
            PyObject *p_returned = PyObject_CallObject(p_fun, NULL);
            if(p_returned != NULL) {
                error = PyLong_AsLong(p_returned);
                Py_DECREF(p_returned);
            } 
            else {
                PyErr_Print();
                error = err_py_returned_null;
            }
        }
        else {
            PyErr_Print();
            error = err_py_fun_name;
        }
    Py_XDECREF(p_fun);
    Py_DECREF(p_module);
    }
    else {
        PyErr_Print();
        error = err_py_module_import;
    }

    return error;
}

error_code inpy_fetch_sentences(char **p_sentences) {
    /* Call python function, return error_code in case of failure */
    error_code error = call_python_function("db_fetch_sentences");
    if(error != err_success) return error;

    /* Open sentences.txt file, return error_code in case of failure */
    FILE *sentences_file = fopen("sentences.txt", "r");
    if(sentences_file == NULL) return err_file_open;

    /* Allocate memory for sentences array and
       Allocate memory for each sentence inside loop.
       Read NO_ROUNDS sentences from sentences text file.
    */
    int i = 0;
    while(i < NO_ROUNDS) {
        p_sentences[i] = malloc(MAX_SEN_LEN);
        if(fgets(p_sentences[i], MAX_SEN_LEN, sentences_file) == NULL) break;
        i++;
    }

    /* Close file(s) and return error_code */
    fclose(sentences_file);
    return err_success;
}

error_code inpy_upload_score(const player new_player) {
    /* open score.txt file or return in case of failure */
    FILE *score_file = fopen("score.txt", "w");
    if(score_file == NULL) {
        return err_file_open;
    }
    /* overwrite the score.txt file (if previous payer info exists)*/
    fprintf(score_file, "%s %d", new_player.name, new_player.score);
    fclose(score_file);

    /* Call python function to upload new score to database and return error_code */
    error_code error = call_python_function("db_upload_score");
    return error;
}

/* For now ignore :
      1. invalid names.
      2. malformed leaderboard.txt file.
*/
error_code inpy_fetch_leaderboard(player **players, size_t *num_players_read) {
    /* Call python function, return error_code in case of failure */
    error_code error = call_python_function("db_fetch_leaderboard");
    if(error != err_success) {
        return error;
    }

    /* Open leaderboard.txt, return error_code in case of failure */
    FILE *leaderboard_file = fopen("leaderboard.txt", "r");
    if(leaderboard_file == NULL) {
        return err_file_open;
    }

    /* Allocatte memory for players array, return error_code in case of failure */
    size_t current_size = 16; /* maybe add a macro for 16*/
    *players = malloc(sizeof(player) * current_size);
    if(*players == NULL) {
        return err_mem_malloc;
    }

    /* scan players records, Expected format : 
            john_doe 67
            raj 44
            more...
    */
    *num_players_read = 0;
    while(fscanf(leaderboard_file, "%31s %d", (*players)[*num_players_read].name, &(*players)[*num_players_read].score) == 2) {
        /* on successfull scan, increment num_players_read */
        (*num_players_read)++;
        /* if current_size limit reached, double the size */
        if(*num_players_read == current_size) {
         current_size *= 2;
            player *temp = realloc(*players, sizeof(player) * current_size);
            if(temp == NULL) {
                /* reallocation failed, stop parsing leaderboard_file */
                error = err_mem_realloc;
                break;
            }
            else {
                *players = temp;
            } 
        }
    }

    /* Close file(s) and return appropriate error_code */
    fclose(leaderboard_file);
    return error;
}
