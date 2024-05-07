SELECT title
FROM movies
JOIN stars, people
ON movies.id = stars.movie_id
AND stars.person_id = people.id
WHERE 
