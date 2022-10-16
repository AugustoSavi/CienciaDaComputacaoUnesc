import AppError from "../../../shared/errors/AppError.js";

class DeleteComputadorService {
    computadorRepository;

    constructor(computadorRepository) {
        this.computadorRepository = computadorRepository;
    }
    
    async execute(id) {
        const computadorExist = await this.computadorRepository.findById(id);
        if (!computadorExist) {
            throw new AppError('Hero não existe');
        }
        return await computadorExist.remove();
    }
}

export { DeleteComputadorService };