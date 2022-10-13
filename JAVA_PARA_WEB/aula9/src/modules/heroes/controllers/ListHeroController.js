class ListHeroesController {
    listHeroesService

    constructor(listHeroesService){
        this.listHeroesService = listHeroesService;
        console.log("ListHeroesController criado")
    }

    async handle(request, response) {
        const heroes = await this.listHeroesService.execute();
        return response.json(heroes);
    }
}

export { ListHeroesController };
