-- https://judge.beecrowd.com/pt/problems/view/2604

select id, name
from products
where price not between 10 and 100;
