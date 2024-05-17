CREATE TABLE transaction (
    user_id INTEGER NOT NULL,
    symbol TEXT NOT NULL,
    price NUMERIC NOT NULL,
    shares NUMERIC NOT NULL,
    cash NUMERIC NOT NULL DEFAULT 10000,
    time DATE NOT NULL,
    FOREIGN KEY (user_id) REFERENCES users(id)
    );
