#es_1 = ['x', 's', 'z']
#es_2 = ['ch', 'sh']
#vowels = ['a', 'e', 'i', 'o', 'u']

def get_plural(s):
    es_1 = ['x', 's', 'z']
    es_2 = ['ch', 'sh']
    vowels = ['a', 'e', 'i', 'o', 'u']
    
    if len(s) > 1:

        if s[-2:] in es_2 or s[-1] in es_1:
            return(s + 'es')

        elif s[-2] not in vowels and s[-1] == 'y':
            return(s[:-1] + 'ies')
    
        elif s[-2:] == 'fe':
            return(s[:-2] + 'ves')
    
        elif s[-1] == 'f':
            return(s[:-1] + 'ves')
    
        elif s[-1] == 'o':
            return(s + 'es')
    
        else:
            return(s + 's')
        
    else:
        if s == 'o':
            return(s + 'es')
        else:
            return(s + 's')
