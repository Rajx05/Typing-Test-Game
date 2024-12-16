# Sample implementaion of python. 
# Changing the file name or function names will trigger errors in interface_py module
error_codes = {
    "err_success": 0,
    "err_server_failure": 1,
    # Other errors..
}

# Function exposed to interfacepy module.
# Using db_ as prefix to these functions.
def db_fetch_sentences():
    # Do actual Database query...
    return error_codes["err_success"]
def db_upload_score():
    return error_codes["err_success"]
def db_fetch_leaderboard():
    return error_codes["err_success"]
