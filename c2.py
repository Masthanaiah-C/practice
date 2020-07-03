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
                    chg="".join(k)
                    return sequenc(org,chg,res)
                else:
                    j+=1
    return res
def sequence():
  
  res=[]
  res=sequenc("AIRMEN","MARINE",res) #amrine armine arimne airmne airmen 
  
  return res
print(sequence())