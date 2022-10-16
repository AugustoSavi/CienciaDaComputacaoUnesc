class ListHeroesController {
    listHeroesService

    constructor(listHeroesService){
        this.listHeroesService = listHeroesService;
    }

    async handle(request, response) {
        const heroes = await this.listHeroesService.execute();
        return response.json(heroes);
    }
}

export { ListHeroesController };
