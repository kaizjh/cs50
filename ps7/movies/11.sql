SELECT movies.title
FROM movies
JOIN people, ratings, stars
ON movies.id = ratings.movie_id
AND movies.id = stars.movie_id
AND stars.person_id = people.id
WHERE people.name = 'Chadwick Boseman'
ORDER BY ratings.rating DESC
LIMIT 5;
