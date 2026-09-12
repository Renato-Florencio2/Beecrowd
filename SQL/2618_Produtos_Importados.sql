-- https://judge.beecrowd.com/pt/problems/view/2618

select prod.name, prov.name, c.name
from products as prod
inner join providers as prov
    on prov.id = prod.id_providers
inner join categories as c
    on prod.id_categories = c.id
where prov.name = 'Sansul SA' and c.name = 'Imported';
