SELECT DISTINCT name FROM people
WHERE id IN (
    SELECT person_id FROM stars
    WHERE movie_id IN (
        SELECT id FROM movies
        WHERE title IN (
            SELECT movies.title
            FROM movies
            JOIN stars, people
            ON movies.id = stars.movie_id
            AND stars.person_id = people.id
            WHERE people.name ='Kevin Bacon'
            AND people.birth = 1958

        )
    )
)
AND people.name != 'Kevin Bacon';
