c = [c1, c2, c3,... cn]

function coin1(A, i)
    if A == 0 return true 
    if A < 0 or i > n return false
    if coin1(A-Ci, i+1) = true return true 
    if coin1(A, i+1) = true return true
    return false 

function coin2(A, i)
    if A == 0 return true 
    if A < 0 return false 
    for j = i + 1 to n do 
        if coin2(A - Cj, j) = true return true
    return false 