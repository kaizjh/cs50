CREATE TABLE history (
    user_id INTEGER NOT NULL,
    symbol TEXT NOT NULL,
    price REAL NOT NULL,
    shares INTEGER NOT NULL,
    cash REAL NOT NULL,
    time TIMESTAMP NOT NULL,
    FOREIGN KEY (user_id) REFERENCES users(id)
    );
