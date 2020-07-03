



def sequence(inz,fnl,res):
    j=0
  
    for i in range(len(inz)-1):
        if (inz[i]==fnl[i]):
            continue
        
    
        else:
            j=i+1
      
            while(j<len(inz)):
                if inz[i]==fnl[j]:
                    res.append((i,j))
                    k=list(fnl)
                    m=k[j]
                    
                    k[j]=k[i]
                    k[i]=m
                    fnl="".join(k)
                    
                    return sequence(inz,fnl,res)
                else:
                     j+=1
    return res
inz="apmy"
fnl="ympa"
res=[]
print(sequence(inz,fnl,res))
  