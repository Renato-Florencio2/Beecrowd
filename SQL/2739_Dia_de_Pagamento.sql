-- https://judge.beecrowd.com/pt/problems/view/2739

select l.name, extract(day from l.payday) as day
from loan as l;
