

Steps to run this project:

1. Run `npm i` command
   
2. Run `npm start` command

3. Connect with de pod
```bash
sudo docker exec -it mongo-aula9 bash
```
4. Execute the shell
```bash
mongosh
```
5. troque o database
```bash
use admin
```

6. Auth de user
```bash
db.auth('root', 'example')
```