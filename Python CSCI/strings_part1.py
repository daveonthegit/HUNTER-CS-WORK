s = input("Please type a string: ")

temp = input("Please type an integer: ")
num = int(temp)

print("The character at index", num, "in string", s, "is", s[num])

print("The three characters starting at index", num, "are", s[num:num+3])

u = s.upper()
l = s.lower()
print("Uppercase:", u)
print("Lowercase:", l)

print(s, "is", len(s), "characters long")
print()

c = input("Please type a single character to search for: ")

print("The first index of", c, "in", s, "is", s.index(c))

if c in s:
        print("The first index of", c, "in", s, "is", s.index(c))
else:
        print(c, "is not in", s)

print(c, "appears", s.count(c), "times in", s)

input("Please press enter to continue")
print()

lst = [10, 20 ,30, 40 ,50, 60 ,70]

print("lst contains", lst)
lst.append(80)
print("lst contains", lst, "after appending 80")

lst.insert(3,35)
print("lst contains", lst, "after inserting 35 at index 3")

del(lst[0])
print("lst contains", lst, "after deleting the item at index 0")

