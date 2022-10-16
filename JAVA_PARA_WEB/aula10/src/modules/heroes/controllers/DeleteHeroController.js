class DeleteHeroController {
    deleteHeroesService

    constructor(deleteHeroesService){
        this.deleteHeroesService = deleteHeroesService;
    }

    async handle(request, response) {
        const { id } = request.params;
        const hero = await this.deleteHeroesService.execute(id);

        return response.status(200).json(hero);
    }
}

export { DeleteHeroController };
