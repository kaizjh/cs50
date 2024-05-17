CREATE TABLE buy (
    user_id INTEGER FOREIGN KEY REFERENCES users(id) NOT NULL,
    symbol TEXT NOT NULL,
    price NUMERIC NOT NULL,
    cash NUMERIC NOT NULL
    );
