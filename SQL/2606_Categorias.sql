-- https://judge.beecrowd.com/pt/problems/view/2606

select p.id, p.name
from products as p
inner join categories as c
    on c.id = p.id_categories
where lower(c.name) like 'super%';
