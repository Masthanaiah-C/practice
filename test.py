import sys

def change(ini):
    if ini=="n":
        return "e"
    if ini=="e":
        return "s"
    if ini=="s":
        return "w"
    if ini=="w":
        return "n"
def dir(ini):
    for i in ["n","e","s","w"]:
        if i==ini:
            return change(ini)
    
    return "None"
def test(k):
    lineno=sys._getframe(1).f_lineno
    if k:
        msg="test at {0} passed".format(lineno)
    else:
        msg="test at {0} failed".format(lineno)
    print(msg)
k=(dir("n")=="e")
test(k)