class UpdateHeroController {
    updateHeroesService

    constructor(updateHeroesService){
        this.updateHeroesService = updateHeroesService;
    }

    async handle(request, response) {
        const { id } = request.params;
        const {name, slug, age} = request.body;
        const hero = await this.updateHeroesService.execute(id, {name, slug, age});

        return response.status(200).json(hero);
    }
}

export { UpdateHeroController };
