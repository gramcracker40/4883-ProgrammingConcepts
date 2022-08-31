numberOfTests = ""
listOfTrees = []

with open("input.txt", "r") as file_object:
  numberOfTests = file_object.readline()

  print(numberOfTests)
  
  counter = 0
  for item in file_object:
    listOfTrees.append(item)
    print(f"{counter} : {item}")
    counter += 1


items = {}

for item in listOfTrees:
  if item in items.keys():
    items[item] += 1
  else:
    items[item] = 1
    
print(items.values())

sum = sum(items.values())
sortedKeys = sorted(items.keys())

counter = 0
sorted(items)
for item in sortedKeys:
  print(f"{item} : {(items[item]/sum) * 100}")
  counter += 1
