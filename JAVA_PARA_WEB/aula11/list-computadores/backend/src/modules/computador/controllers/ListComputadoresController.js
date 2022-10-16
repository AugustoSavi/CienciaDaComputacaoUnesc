class ListComputadoresController {
    listComputadoresService

    constructor(listComputadoresService){
        this.listComputadoresService = listComputadoresService;
    }

    async handle(request, response) {
        const computador = await this.listComputadoresService.execute();
        return response.json(computador);
    }
}

export { ListComputadoresController };
