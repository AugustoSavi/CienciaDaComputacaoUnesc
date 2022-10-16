class FindOneHeroesController {
    findOneHeroesService

    constructor(findOneHeroesService){
        this.findOneHeroesService = findOneHeroesService;
    }

    async handle(request, response) {
        const {id} = request.params;
        const hero = await this.findOneHeroesService.execute(id);
        return response.json(hero);
    }
}

export { FindOneHeroesController };
