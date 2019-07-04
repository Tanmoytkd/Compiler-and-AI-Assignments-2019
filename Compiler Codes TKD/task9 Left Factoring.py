#!/usr/bin/env python
# coding: utf-8

# In[ ]:





# In[1]:


from itertools import zip_longest

def find_prefixes(strings):
    zipped = zip_longest(*strings, fillvalue='')
    for index, letters in enumerate(zipped):
        if index == 0:
            prefixes = letters  # assumes there will always be a prefix
        else:
            poss_prefixes = [prefix + letters[i] for i, prefix in enumerate(prefixes)]
            prefixes = [prefix if poss_prefixes.count(prefix) == letters.count(prefix)  # changed > 1 to == letters.count(prefix)
                        else prefixes[i] for i, prefix in enumerate(poss_prefixes)]
    return set(prefixes)


# In[2]:


def find_prefix_suffixes(strings, prefixes):
    prefix_suffix = dict()
    for s in strings:
        for prefix in sorted(list(prefixes), key=lambda x: len(x), reverse=True):
            if s.startswith(prefix):
                if prefix in prefix_suffix:
                    prefix_suffix[prefix].add(s.replace(prefix, '', 1))
                else:
                    prefix_suffix[prefix] = set([s.replace(prefix, '', 1)])
    return prefix_suffix


# In[3]:


prod = input("Please enter the production: ");
splitted = prod.split('|')

production_name = splitted[0].split('->')[0]
productions = [splitted[0].split('->')[1]]+splitted[1:]

#S->ab|abc|abcd|acd|bc|bd|d
#S->aBc|aCd|bCa|d


# In[4]:


s = productions 
prefixes = find_prefixes(s)

suffixes = find_prefix_suffixes(s, prefixes)

print(production_name+'->', end='')

for i, prefix in enumerate(prefixes, start=1):
    if i>1:
        print('|', end='')
    print(prefix, end='')
    suf = suffixes.get(prefix, '')
    if len(suf)>0 and not list(suf)[0]=='':
        print(production_name, end='')
        for j in range(i):
            print("'", end='')
print('')
        
for i, prefix in enumerate(prefixes, start=1):
    suf = suffixes.get(prefix, '')
    if len(suf)>0 and not list(suf)[0]=='':
        print(production_name, end='')
        for j in range(i):
            print("'", end='')
        print('->', end='')
        suf = suffixes.get(prefix, '')
        for k, suffix in enumerate(suf):
            if k>0:
                print('|', end='')
            print(suffix, end='')
        print('')
    
  

