/* "Game" Database for Typing-Test-Game
   contains 3 tables:
        1. Sentences (contains sentences to type)
        2. Players (contains player info, like name, password etc., )
        3. LeaderBoard (contains player's score)
*/

CREATE  DATABASE Game;       -- Only on first run.
use Game;
TRUNCATE TABLE Sentences;   -- To avoid multiple inserts on each run.

CREATE TABLE Sentences(     -- Only on first run.
    Sentence varchar(200),
    Difficulty int
);

INSERT INTO Sentences VALUES
("Water is essential for life.", 1),
("I hate doing homework.", 1),
("CANADA reported 312 new cases today.", 2),
("Car 204 crossed the finish line first.", 2), 
("The plane to JAPAN leaves @10:05 PM.", 3),
("Bus 78 will leave the station at 5 PM.", 3);
-- Add more rows! Either manullay or automate with python

/* Select one sentence from each difficulty level */
WITH RankedSentences AS (
    SELECT *,
           ROW_NUMBER() OVER (PARTITION BY Difficulty ORDER BY RAND()) AS r
    FROM Sentences
)
SELECT Sentence, Difficulty
FROM RankedSentences
WHERE r = 1;

/*
CREATE other tables */
