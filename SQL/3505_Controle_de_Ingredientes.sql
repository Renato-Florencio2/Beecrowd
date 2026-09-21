-- https://judge.beecrowd.com/pt/problems/view/3505

select i.nome, i.kg
from ingrediente as i
where i.kg < 10 and i.kg > 0
order by i.kg ASC;
