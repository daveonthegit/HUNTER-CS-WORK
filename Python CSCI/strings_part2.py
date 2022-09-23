lst = [10, 20, 30, 40, 50, 60 ,70]

new_lst = lst[1:4]
print("new_lst contains", new_lst)
print()

print("Each element of lst, one at a time:")
for x in lst:  
        print(x)
print()


next_lst = []
for var in lst:
        next_lst.append(var * 3)
print("next_lst was built by multiplying lst by three and contains", next_lst)
print()
