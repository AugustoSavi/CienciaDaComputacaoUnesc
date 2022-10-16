class CreateHeroesController {
    createHeroesService

    constructor(createHeroesService){
        this.createHeroesService = createHeroesService;
    }

    async handle(request, response) {
        const {name, slug, age} = request.body;
        const hero = await this.createHeroesService.execute({name, slug, age});

        return response.status(201).json(hero);
    }
}

export { CreateHeroesController };
