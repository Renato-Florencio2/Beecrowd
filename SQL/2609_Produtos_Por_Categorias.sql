-- https://judge.beecrowd.com/pt/problems/view/2609

select c.name, sum(p.amount)
from categories as c
join products as p
    on c.id = p.id_categories
group by c.id;
