def question1(s):
  return s.count("e")

def question2(s):
  return s.lower().count("e")

def question3(s):
  return s.lower().count("a") + s.lower().count("e") + s.lower().count("i") + s.lower().count("o") + s.lower().count("u") 

# change this to do other tests 
st = "ExampleString" 
st1 = "Another Example"

print("#1:", question1(st))
print("#2:", question2(st))
print("#3:", question3(st))
print("#1:", question1(st1))
print("#2:", question2(st1))
print("#3:", question3(st1))
