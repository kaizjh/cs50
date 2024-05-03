books = []

for i in range(3):
    book = dict
    book['author'] = input("Enter a author: ")
    book['title'] = input('Enter a title: ')
    books.append(book)

for book in books:
    print(f"{book['author']} wrote {book['title']}")
