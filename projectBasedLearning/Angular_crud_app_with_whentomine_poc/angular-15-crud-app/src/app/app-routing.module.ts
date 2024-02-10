import { NgModule } from '@angular/core';
import { RouterModule, Routes } from '@angular/router';
//import { PostModule } from './post/post.module';

const routes: Routes = [
  //{ path: '', component: PostModule }
];

@NgModule({
  imports: [RouterModule.forRoot(routes)],
  exports: [RouterModule]
})
export class AppRoutingModule {}
