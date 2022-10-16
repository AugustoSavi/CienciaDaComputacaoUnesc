

## Steps to run this project:

1. Run `sudo docker-compose up -d` command

2. Run `npm i` command
   
3. Run `npm start` command

## Se der erro de autenticação com o mongo

1. Run `sudo docker exec -it mongo-computador bash` command
   
2. Run `mongosh` command

3. Run `use admin` command

4. Run `db.auth('root', 'example')` command


## Exemplos de curl

### 1. Create computador
```bash
curl --request POST \
  --url http://localhost:5000/computador \
  --data '{
	"name": "teste1",
	"slug": "teste1",
	"age": 123
}'
```

### 2. listar todos computadores
```bash
curl --request GET \
  --url http://localhost:5000/computador
```

### 3. Buscar um computador
```bash
curl --request GET \
  --url http://localhost:5000/computador/{id}
```

### 4. Update computador
```bash
curl --request PUT \
  --url http://localhost:5000/computador/{id} \
  --data '{
	"name": "teste update 1",
	"slug": "teste update 1",
	"age": 2
}'
```
### 5. Delete computador
```bash
curl --request DELETE \
  --url http://localhost:5000/computador/{id}
```
