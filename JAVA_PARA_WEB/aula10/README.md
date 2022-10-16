

## Steps to run this project:

1. Run `sudo docker-compose up -d` command

2. Run `npm i` command
   
3. Run `npm start` command

## Se der erro de autenticação com o mongo

1. Run `sudo docker exec -it mongo-hero bash` command
   
2. Run `mongosh` command

3. Run `use admin` command

4. Run `db.auth('root', 'example')` command


## Exemplos de curl

### 1. Create hero
```bash
curl --request POST \
  --url http://localhost:5000/heroes \
  --data '{
	"name": "teste1",
	"slug": "teste1",
	"age": 123
}'
```

### 2. listar todos heroes
```bash
curl --request GET \
  --url http://localhost:5000/heroes
```

### 3. Buscar um hero
```bash
curl --request GET \
  --url http://localhost:5000/heroes/{id}
```

### 4. Update hero
```bash
curl --request PUT \
  --url http://localhost:5000/heroes/{id} \
  --data '{
	"name": "teste update 1",
	"slug": "teste update 1",
	"age": 2
}'
```
### 5. Delete hero
```bash
curl --request DELETE \
  --url http://localhost:5000/heroes/{id}
```
