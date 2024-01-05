import * as telco from "../lib";
import { targetProgram } from "./data";

export class LabRat {
    private constructor(private _pid: number) {
    }

    get pid(): number {
        return this._pid;
    }

    static async start(): Promise<LabRat> {
        const pid = await telco.spawn(targetProgram(), {
            stdio: telco.Stdio.Pipe
        });
        await telco.resume(pid);
        // TODO: improve injectors to handle injection into a process that hasn't yet finished initializing
        await sleep(50);

        return new LabRat(pid);
    }

    stop(): void {
        telco.kill(this._pid);
    }
}

function sleep(delay: number): Promise<void> {
    return new Promise(resolve => {
        setTimeout(() => { resolve(); }, delay);
    });
}
