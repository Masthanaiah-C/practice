import csv
with open ("data.csv") as file:
    rr=csv.DictReader(file,delimiter=",",quotechar='"')
    k=rr
    with open("output.txt","w") as out:
        for i in k:
            out.write("https://github.com/"+i['Name']+"/assignment.git\n")


    
   
    