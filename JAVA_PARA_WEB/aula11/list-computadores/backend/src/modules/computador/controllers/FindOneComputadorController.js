class FindOneComputadorController {
    findOneComputadorService

    constructor(findOneComputadorService){
        this.findOneComputadorService = findOneComputadorService;
    }

    async handle(request, response) {
        const {id} = request.params;
        const computador = await this.findOneComputadorService.execute(id);
        return response.json(computador);
    }
}

export { FindOneComputadorController };
