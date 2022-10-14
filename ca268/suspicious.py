import sys
with open(sys.argv[1], "r") as first_file:
    students = first_file.readlines()
with open(sys.argv[2], "r") as second_file:
    delinquents = second_file.readlines()
trouble = []
for student in students:
    for delinq in delinquents:
        if delinq == student:
            trouble.append(delinq)
i = 0
new_trouble = sorted(trouble)
while i < len(new_trouble):
    number = str(i + 1)
    print(number + ".", new_trouble[i][:-1])
    i += 1
