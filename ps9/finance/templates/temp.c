CREATE TABLE buy (
    user_id INTEGER NOT NULL,
    symbol TEXT NOT NULL,
    price NUMERIC NOT NULL,
    cash NUMERIC NOT NULL,
    FOREIGN KEY (user_id) REFERENCES users(id)
    );
