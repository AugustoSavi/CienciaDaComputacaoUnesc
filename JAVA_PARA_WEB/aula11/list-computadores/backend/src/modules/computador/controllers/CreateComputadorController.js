class CreateComputadorController {
    createComputadorService

    constructor(createComputadorService){
        this.createComputadorService = createComputadorService;
    }

    async handle(request, response) {
        const { hostname, processador, memoria, armazenamento, estado } = request.body;
        console.log(request.body)
        const computador = await this.createComputadorService.execute({ hostname, processador, memoria, armazenamento, estado });

        return response.status(201).json(computador);
    }
}

export { CreateComputadorController };
