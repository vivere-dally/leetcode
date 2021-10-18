# Company hierarchy

In a company's hierarchy, some employees manage other employees, who can in turn manage other employees.

The input (as a string) format for the hierarchy is (name, sub-hierarchy_1, sub-hierarchy_2,... , sub-hierarchy_n), with every sub-hierarchy having the same format, recursively.

Your task is to write code that parses the hierarchy, removes employees that are marked as "Unavailable" along with all the employees they manage and prints the resulting hierarchy.

Input: ("John", ("Jasmine", ("Jay"), ("Unavailable")), ("Unavailable", ("Jack", ("Jeremy"))), ("Johanna"))
Output: ("John", ("Jasmine", ("Jay")), ("Johanna"))

## Notes

This looks like a classical `lisp` problem, so I included a solution here:

```lisp
(defun company_hierarchy(l)
    (cond
        ( (null l)
            nil
        )
        
        ( (not (listp l))
            '(l)
        )
        
        ( (string= (car l) "Unavailable")
            (company_hierarchy (cdr (cdr (cdr l)))) ; skip current, subHierarchy[i], subHierarchy[i + 1]
        )
        
        (t (append
                (company_hierarchy (car l))
                (company_hierarchy (car (cdr l)))
                (company_hierarchy (car (cdr (cdr l))))
            )
        )
    )
)
```
