import csv
with open("create.pd","w",newline='') as pdf:
    head=csv.DictWriter(pdf,fieldnames=['name','user id'],delimiter=':')
    head.writeheader()
    a="apple"
    head.writerow({'name':''.join(a),'user id':'Masthanaiah-C'})
    head.writerow({'name':'masthan2','user id':'Masthanaiah-C'})