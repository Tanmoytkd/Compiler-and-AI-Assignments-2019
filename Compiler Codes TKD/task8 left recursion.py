txt = input("Please enter the productions: ")
parts = txt.split('->')
left = parts[0]
right = parts[1]
right_parts = right.split('|')
if right_parts[0].startswith(left[0]):
    print("{}->{}{}'".format(left, right_parts[1], left))
    print("{}'->{}{}'".format(left, right_parts[0][1:], left))
    print("{}'->∈".format(left))
else:
    print("There is no left recursion")
