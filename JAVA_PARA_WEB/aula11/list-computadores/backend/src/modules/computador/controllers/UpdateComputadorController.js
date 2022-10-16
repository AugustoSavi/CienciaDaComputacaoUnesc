class UpdateComputadorController {
    updateComputadorService

    constructor(updateComputadorService){
        this.updateComputadorService = updateComputadorService;
    }

    async handle(request, response) {
        const { id } = request.params;
        const { hostname, processador, memoria, armazenamento, estado } = request.body;
        const computador = await this.updateComputadorService.execute(id, { hostname, processador, memoria, armazenamento, estado });

        return response.status(200).json(computador);
    }
}

export { UpdateComputadorController };
