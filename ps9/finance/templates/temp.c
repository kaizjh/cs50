CREATE TABLE buy (
    user_id INTEGER NOT NULL,
    symbol TEXT NOT NULL,
    price NUMERIC NOT NULL,
    shares NUMERIC NOT NULL,
    cash NUMERIC NOT NULL,
    time TIMESTAMP NOT NULL,
    FOREIGN KEY (user_id) REFERENCES users(id)
    );
