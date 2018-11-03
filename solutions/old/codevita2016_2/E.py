#  Original language
"""
O1 -> {M2}
M2 -> P3 | P3, M2
P3 -> :O1 | : | :A4
A4 -> [ E5 ]
E5 ->  01, E5 | 01

"""

# Language in chomsky form
"""
Start S0
S0 -> {M2} | {}
01 -> {M2} | {}
M2 -> P3 | P3, M2

P3 -> :O1 | : | :A4
A4 -> [ E5 ] , 
E5 ->  O1,E5 | {M2} | {}

"""
"""
Start S

S -> ZR | LR
D -> ZR | LR
M ->  CA | CO | YM
A -> XK
E ->  WE | ZR | LR

Z -> LM
Y -> CQ
X -> JE
W -> DQ

L -> {
M -> :
R -> }
J -> [
K -> ]
C -> :
Q -> ,

"""


#  Validate if reg_exp is part of the Grammar
def validate(reg_exp):
    # Find the Grammar for the  Language
    grammar = build_grammar() 
    start = ['S'] 

    # Run CYK algo
    return cyk_algo(reg_exp,grammar,start)

# Build grammar as per the comments on top of this file
def build_grammar():
    grammar = {} 
    grammar['S'] = []
    grammar['S'].append('ZR')
    grammar['S'].append('LR')

    grammar['D'] = ['ZR']
    grammar['D'].append('LR')

    grammar['M'] = ['CA']
    grammar['M'].append('CD')
    grammar['M'].append('YM')

    grammar['A'] = ['XK']

    grammar['E'] = ['WE']
    grammar['E'].append('LR')
    grammar['E'].append('ZR')

    grammar['Z'] = ['LM']
    grammar['Y'] = ['MQ']
    grammar['X'] = ['JE']
    grammar['W'] = ['DQ']

    grammar['L'] = ['{']
    grammar['M'].append(':')
    grammar['R'] = ['}']
    grammar['J'] = ['[']
    grammar['K'] = [']']
    grammar['C'] = [':']
    grammar['Q'] = [',']

    return grammar


#  CYK algo
def cyk_algo(exp, g, start):

    l = len(exp)

    # Create a matrix of elements with each element being an empty set
    x = [ [set() for j in range(l+1)] for i in range(l+1) ]

    for i in range(l):
        # for each production, check if A->exp[i], then add A to x[i,i+1]
        for lhs_prod in g:
            for rhs_prod in g[lhs_prod]:
                if len(rhs_prod) == 1  and rhs_prod == exp[i]:
                    x[i][i+1].add(lhs_prod)


    # Run algo after Initializing
    for i in range(2,l+1):                   # Length of the sub-string      
        for j in range(0,l-i+1):             # Value of starting index of substring
            for br in range(j+1 ,j+i):       # Splitting point of the substring
                    
                # Assign two temp variables
                temp1 = x[j][br]
                temp2 = x[br][j+i]

                # For every Production present(iterate)
                for lhs_prod in g:
                    for rhs_prod in g[lhs_prod]:
                        # If rhs_producction has length 2
                        if len(rhs_prod) == 2  :
                            c1 = set([rhs_prod[0]])
                            c2 = set([rhs_prod[1]])
                            # If X->AB and A is in x[i,br] and B in x[br,i+j] then : add X to x[i,i+j]
                            #  if(i==3):
                                #  print(lhs_prod, c1,c2,temp1,temp2)

                            if len(c1&temp1) * len(c2&temp2) != 0:
                                x[j][j+i].add(lhs_prod)

    #  for a in x:
        #  print(a)
    

    #  If Start in x[0,l], then It is part of the grammar
    if( len (x[0][l] & set(start) ) !=0):
        return True
    else:
        return False

x = input()
a = (validate(x))
if a:
    print(1)
else:
    print(-1)




