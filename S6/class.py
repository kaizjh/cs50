class Student():

    def __init__(self, name, id):
        self.name = name
        self.id  = id

    def changeID(self, id):
        self.id = id

    def print(self):
        print(f"{name} - {id}", self.name, self.id)


jane = Student("Jane", 19)
jane.print()

jane.changeID(11)
jane.print()
