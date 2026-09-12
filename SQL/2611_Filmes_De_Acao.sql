-- https://judge.beecrowd.com/pt/problems/view/2611

select m.id, m.name
from movies as m
inner join genres as g
    on g.id = m.id_genres
where g.description = 'Action';
