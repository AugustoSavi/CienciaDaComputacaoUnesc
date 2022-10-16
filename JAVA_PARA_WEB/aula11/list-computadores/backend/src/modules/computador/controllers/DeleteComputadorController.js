class DeleteComputadorController {
    deleteComputadorService

    constructor(deleteComputadorService){
        this.deleteComputadorService = deleteComputadorService;
    }

    async handle(request, response) {
        const { id } = request.params;
        const computador = await this.deleteComputadorService.execute(id);

        return response.status(200).json(computador);
    }
}

export { DeleteComputadorController };
