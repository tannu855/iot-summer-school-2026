import os

count = 0

for file in os.listdir("."):
    if file.endswith(".ino"):
        count += 1

print("Total .ino files:", count )
