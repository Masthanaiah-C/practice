
def sequenc(org,chg,res):
    j=0
  
    for i in range(len(org)-1):
        if (org[i]==chg[i]):
            continue
        else:
            j=i+1
            while(j<len(org)):
                if(org[i]==chg[j]):
                    for k in range(i,j):
                        res.append((k,k+1))
                    if(j>1):
                        for k in range(j-1,i,-1):
                            res.append((k,k-1))
                    k=list(chg)
                    m=k[j]
                    k[j]=k[i]
                    k[i]=m
                    chg=k
                    return sequenc(org,chg,res)
                else:
                    j+=1
    return res
def sequence(p):
  k=list(range(len(p)))
  res=[]
  res=sequenc(k,p,res) #amrine armine arimne airmne airmen 
  
  return len(res)
p=[2,4,6,8,0,9,7,5,1,3]
print(sequence(p))