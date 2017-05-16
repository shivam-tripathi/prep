SELECT CASE 
           WHEN A = B and B = C THEN "Equilateral" 
           WHEN A + B <= C or B + C <= A or A + C <= B THEN "Not A Triangle" 
           WHEN A = B or B = C or A = C THEN "Isosceles"
           ELSE "Scalene"
       END 
FROM TRIANGLES