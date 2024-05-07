SELECT movies.title, ratings.rating
FROM movies
JOIN ratings
ON ratings.movie_id = movies.id
WHERE movies.year = 2010
AND ratings.rating > 0
ORDER BY ratings.rating
DESC
LIMIT 100;