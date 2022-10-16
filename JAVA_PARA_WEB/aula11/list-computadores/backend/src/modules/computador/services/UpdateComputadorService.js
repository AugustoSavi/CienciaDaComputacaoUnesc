import AppError from "../../../shared/errors/AppError.js";

class UpdateComputadorService {
    computadorRepository;

    constructor(computadorRepository) {
        this.computadorRepository = computadorRepository;
    }
    
    async execute(id, { hostname, processador, memoria, armazenamento, estado }) {
        const computadorExist = await this.computadorRepository.findById(id);
        if (!computadorExist) {
            throw new AppError('Computador não existe');
        }
        
        computadorExist.hostname = hostname;
        computadorExist.processador = processador;
        computadorExist.memoria = memoria;
        computadorExist.armazenamento = armazenamento;
        computadorExist.estado = estado;
        computadorExist.__v = computadorExist.__v + 1;

        return await computadorExist.save();
    }
}

export { UpdateComputadorService };